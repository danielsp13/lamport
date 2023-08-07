FROM frolvlad/alpine-gcc

LABEL maintainer="danielperezruiz.10@gmail.com" \
      version="0.0.0"
      
RUN apk add --no-cache bash make sudo

SHELL ["/bin/bash", "-c"]

RUN adduser -D lamport

RUN mkdir -p /app/test/bin && \
    chown lamport --recursive /app

ENV HOME="/home/lamport"

WORKDIR /app/test

COPY --chown=lamport Makefile ./

RUN make install_compiler_dependencies &&\
    make install_tests_dependencies &&\
    rm Makefile

USER lamport

ENTRYPOINT ["make","virtual_test"]
