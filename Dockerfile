FROM alpine:latest
RUN apk add git cmake g++ make

ENTRYPOINT ["/bin/sh"]
