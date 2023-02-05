FROM alpine:latest
RUN apk add git cmake g++ make boost-dev curl gnupg coreutils
RUN apk add lcov --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/

ENTRYPOINT ["/bin/sh"]
