FROM alpine:latest
RUN apk add git cmake g++ make boost-dev curl gnupg coreutils

ENTRYPOINT ["/bin/sh"]
