from http.server import BaseHTTPRequestHandler, HTTPServer

# HTTPRequestHandler sınıfı
class HTTPServer_RequestHandler(BaseHTTPRequestHandler):

    # GET fonksiyonu
    def do_GET(self):
        # status kodunu gönder
        self.send_response(200)

        # header'ları gönder
        self.send_header('Content-type','text/html')
        self.end_headers()

        # istemciye gönderilecek mesajı belirle
        if self.path == "/":
            message = "Hello, world!"
        else:
            name = self.path[1:]
            message = "Hello, {}!".format(name)

        # mesajı yaz
        self.wfile.write(bytes(message, "utf8"))
        return

def run():
  print('starting server...')

  # set up server
  port = 8080
  server_address = ('0.0.0.0', port)
  httpd = HTTPServer(server_address, HTTPServer_RequestHandler)

  # run server
  print('running server on port {}...'.format(port))
  httpd.serve_forever()


run()