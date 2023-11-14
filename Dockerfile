# ----- Etapa de construccion
FROM alpine:3.16 as builder

LABEL maintainer="danielperezruiz.10@gmail.com" \
      version="0.0.9"

RUN apk add --no-cache bash make sudo libc-dev flex-dev libexecinfo-dev

SHELL ["/bin/bash", "-c"]

RUN adduser -D lamport

RUN mkdir -p /builddir && \
    chown lamport --recursive /builddir

ENV HOME="/home/lamport"

WORKDIR /builddir

COPY --chown=lamport ./include ./include
COPY --chown=lamport ./src ./src
COPY --chown=lamport Makefile ./

RUN make install_interpreter_dependencies &&\
	make compile_static &&\
    rm Makefile

RUN rm -r ./include/* &&\
	rm -r ./src/* &&\
	rm -r ./obj/*

# ----- Etapa final
FROM alpine:3.16

RUN apk add bash flex-dev bison

LABEL maintainer="danielperezruiz.10@gmail.com" \
      version="0.0.9"
      
SHELL ["/bin/bash", "-c"]

RUN adduser -D lamport

ENV HOME="/home/lamport"

COPY --from=builder /builddir/bin /bin

RUN echo '#!/bin/sh' > /bin/launch_lmp.sh && \
    echo '/bin/lmp $ENV_LMP_FILE' >> /bin/launch_lmp.sh && \
    chmod +x /bin/launch_lmp.sh

USER lamport

WORKDIR /app/

CMD ["/bin/launch_lmp.sh"]
