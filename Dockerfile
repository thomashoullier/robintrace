FROM alpine:latest
RUN apk add git cmake g++ make boost-dev

ENTRYPOINT ["/bin/sh"]
