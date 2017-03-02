// import cors from 'cors'
// import express from 'express'
// import mongoose from 'mongoose'
// import bodyParser from 'body-parser'
//
// import glob from 'glob'
// import fs from 'fs'
// import params  from '../../params'
// /* Test Framework */
// import Mocha from 'mocha'
//
// import istanbul from 'istanbul'
// import event from './event/index.js'
//
// var istanbul_core = require('../../node_modules/istanbul-middleware/lib/core');
// istanbul_core.hookLoader('[./model/Game.model]');
//
// const app = express()
// var server = require('http').createServer(app);
//
// import path from 'path'
// import recursive from 'recursive-readdir'
//
// import Logger from './utils/Logger'
//
// const env = process.env.NODE_ENV || 'development'
// const config = params
// //const mongoAdapter = require('socket.io-mongodb');
// require("babel-core/register");
// require("babel-polyfill");
//
// // Enable Cross Origin Resource Sharing
// app.use(cors())
//
// // Enable auto parsing of json content
// app.use(bodyParser.json())
// app.use(bodyParser.urlencoded({ extended: true }))
// global.io = require('socket.io')(server)
// // Use native promise API with mongoose
// mongoose.Promise = global.Promise
//
// // Mongoose connection
// /* eslint-disable no-console */
// /* eslint-disable max-nested-callbacks */
// mongoose.connect(`mongodb://${config.db.host}:${config.db.port}/${config.db.dbName}`)
// const db = mongoose.connection
// db.on('error', err => {
//   Logger.error('FAILED TO CONNECT', err)
//   process.exit(1)
// })
//
//
// // Launch the application
// io.on('connection', (socket) => {
//   event(socket)
//  })
//
// db.once('open', () => {
//     app.emit('ready')
//     Logger.success(`Test app listening on port 5000 !`)
//     Logger.info('[TEST] Launching test runner...')
//
//     const mocha = new Mocha({
//       reporter: 'dot',
//       timeout: '2000',
//     })
//     const collector = new istanbul.Collector()
//     const reporter = new istanbul.Reporter()
//     const testsDirectory = './test'
//
//     recursive(testsDirectory, (err, files) => {
//       if (err) {
//         process.exit(2)
//       }
//       Logger.info('[TEST] Listing test files...')
//       files.filter(file => {
//         return file.substr(-9) === '.tests.js'
//       }).forEach(file => {
//         mocha.addFile(
//           path.join('./', file)
//         )
//       })
//
//       process.env.ROUTETEST = `http://localhost:5000`
//
//       mocha.run(errCount => {
//         mongoose.connection.db.dropDatabase()
//
//         collector.add(global.__coverage__)
//         reporter.addAll(['text-summary', 'html'])
//         reporter.write(collector, true, () => {
//           Logger.info('\nCoverage report saved to coverage/index.html')
//         })
//
//         if (errCount > 0) {
//           Logger.info(`Total error${(errCount > 1 ? 's' : '')}: ${errCount}`)
//           process.exit(1)
//         }
//         process.exit(0)
//       })
//     })
//   })
//
//
//  server.listen(5000, function(){
//    console.log('listening on 5000');
//  });
//
//
// /* eslint-enable max-nested-callbacks */
// /* eslint-enable no-console */
// /* eslint-enable max-nested-callbacks*/
"use strict";