# C TCP/HTTP JSON Server

A simple C server built to **understand socket programming** by sending JSON responses over HTTP. This project demonstrates:

* Creating TCP sockets
* Binding and listening on a port
* Accepting multiple client connections
* Sending HTTP-compliant responses with JSON data

---

## **Motivation**

I built this server to learn **low-level socket programming in C** and understand how higher-level frameworks (Node.js, Python Flask) work under the hood. This project focuses on **hands-on experience** with:

* `socket()`, `bind()`, `listen()`, `accept()`, `send()`, `close()`
* How HTTP headers allow browsers to correctly interpret TCP data
* JSON formatting and sending structured data

---

## **References & Documentation**

I used the following official documentation and resources while building this project:

* [socket(2) — Linux manual page](https://man7.org/linux/man-pages/man2/socket.2.html)
* [bind(2) — Linux manual page](https://man7.org/linux/man-pages/man2/bind.2.html)
* [listen(2) — Linux manual page](https://man7.org/linux/man-pages/man2/listen.2.html)
* [accept(2) — Linux manual page](https://man7.org/linux/man-pages/man2/accept.2.html)
* [send(2) — Linux manual page](https://man7.org/linux/man-pages/man2/send.2.html)
* [C string formatting & escaping in JSON](https://en.cppreference.com/w/c/string/byte)

---

## **How to Build**

1. Save the server code as `server.c`.
2. Compile with GCC:

```bash
gcc server.c -o server
```

3. Run the server:

```bash
./server
```

---

## **How to Test**

* **CLI Test** (raw TCP):

```bash
nc 127.0.0.1 8080
```

You should see your JSON message appear.

* **Browser Test** (HTTP JSON):
  Open:

```
http://localhost:8080
```

You should see JSON displayed:

```json
{"message":"fuck nodejs and python devs"}
```

* **Multiple Clients**
  Reloading the browser or opening multiple `nc` sessions will work because the server uses a **while loop** to handle multiple connections sequentially.

---

## **Project Structure**

```
server.c         # main TCP/HTTP server source file
README.md        # project documentation
Makefile         # make file
```

---

## **Key Learnings**

* TCP vs HTTP: TCP just moves bytes; HTTP adds headers so browsers can understand the content.
* Socket lifecycle: `socket() -> bind() -> listen() -> accept() -> send() -> close()`
* Escaping JSON in C strings (`\"`)
* Handling multiple clients with a `while(1)` loop