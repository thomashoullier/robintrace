FROM alpine:latest
RUN apk add git cmake gcc

ENTRYPOINT ["/bin/sh"]
