const params = {
  db: {
  host: 'localhost',
  port: '27017',
  dbName: 'red-tetris',
  },
  server: {
     host: '0.0.0.0',
     port: 5000,
     url: 'localhost:5000',
     get url(){ return 'http://' + this.host + ':' + this.port }
  },
}

module.exports = params
