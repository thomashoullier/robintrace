FROM alpine:latest
RUN apk add git cmake gcc make

ENTRYPOINT ["/bin/sh"]
