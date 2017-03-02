import params  from '../../params'

import cors from 'cors'
import express from 'express'
import mongoose from 'mongoose'
import bodyParser from 'body-parser'
import event from './event/index.js'

const app = express()
var server = require('http').createServer(app);


const env = process.env.NODE_ENV || 'development'
const config = params
require("babel-core/register");
require("babel-polyfill");

app.use(cors())
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: true }))
global.io = require('socket.io')(server)
mongoose.Promise = global.Promise

mongoose.connect(`mongodb://${config.db.host}:${config.db.port}/${config.db.dbName}`)

const db = mongoose.connection
db.on('error', err => {
  console.log('FAILED TO CONNECT', err)
  process.exit(1)
})

app.get('/',(req, res) => res.end())

io.on('connection', (socket) => {
  event(socket)
 })

db.once('open', () => {
  //app.listen(config.server.port)
  app.emit('ready')
//  console.log(`App is running and listening to port ${config.server.port}`)
})


 server.listen(5000, function(){
   console.log('listening on 5000');
 });
