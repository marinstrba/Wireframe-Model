FROM ubuntu:22.04

WORKDIR /app

COPY . /app                              

RUN apt-get update && apt-get install -y gcc make

RUN make 

CMD [ "./myprogram" ]