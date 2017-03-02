'use strict';

var _params = require('../../params');

var _params2 = _interopRequireDefault(_params);

var _cors = require('cors');

var _cors2 = _interopRequireDefault(_cors);

var _express = require('express');

var _express2 = _interopRequireDefault(_express);

var _mongoose = require('mongoose');

var _mongoose2 = _interopRequireDefault(_mongoose);

var _bodyParser = require('body-parser');

var _bodyParser2 = _interopRequireDefault(_bodyParser);

var _index = require('./event/index.js');

var _index2 = _interopRequireDefault(_index);

var _Logger = require('./utils/Logger');

var _Logger2 = _interopRequireDefault(_Logger);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var app = (0, _express2.default)();
var server = require('http').createServer(app);

var env = process.env.NODE_ENV || 'development';
var config = _params2.default;
require("babel-core/register");
require("babel-polyfill");

app.use((0, _cors2.default)());
app.use(_bodyParser2.default.json());
app.use(_bodyParser2.default.urlencoded({ extended: true }));
global.io = require('socket.io')(server);
_mongoose2.default.Promise = global.Promise;

_mongoose2.default.connect('mongodb://' + config.db.host + ':' + config.db.port + '/' + config.db.dbName);

var db = _mongoose2.default.connection;
db.on('error', function (err) {
  _Logger2.default.error('FAILED TO CONNECT', err);
  process.exit(1);
});

app.get('/', function (req, res) {
  return res.end();
});

io.on('connection', function (socket) {
  (0, _index2.default)(socket);
});

db.once('open', function () {
  //app.listen(config.server.port)
  app.emit('ready');
  _Logger2.default.info('App is running and listening to port ' + config.server.port);
});

server.listen(5000, function () {
  console.log('listening on 5000');
});