'use strict';

var _redux = require('redux');

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactDom = require('react-dom');

var _reactDom2 = _interopRequireDefault(_reactDom);

var _reactRedux = require('react-redux');

var _reduxThunk = require('redux-thunk');

var _reduxThunk2 = _interopRequireDefault(_reduxThunk);

var _reduxLogger = require('redux-logger');

var _reduxLogger2 = _interopRequireDefault(_reduxLogger);

var _reactRouter = require('react-router');

var _reactRouterRedux = require('react-router-redux');

var _socket = require('socket.io-client');

var _socket2 = _interopRequireDefault(_socket);

var _socketIoMiddleWare = require('./middleware/socketIoMiddleWare');

var _socketIoMiddleWare2 = _interopRequireDefault(_socketIoMiddleWare);

var _reducers = require('./reducers');

var _reducers2 = _interopRequireDefault(_reducers);

var _app = require('./containers/app');

var _app2 = _interopRequireDefault(_app);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

require("babel-core/register");
require("babel-polyfill");

var configureStore = function configureStore(reducer, socket) {
  return (0, _redux.createStore)((0, _redux.combineReducers)({
    routing: _reactRouterRedux.routerReducer,
    game: reducer
  }), composeEnhancers((0, _redux.applyMiddleware)((0, _socketIoMiddleWare2.default)(socket),
  //createLogger(),
  _reduxThunk2.default)));
};

var socket = (0, _socket2.default)('localhost:5000');
var composeEnhancers = window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || _redux.compose;
var store = configureStore(_reducers2.default, socket);
var history = (0, _reactRouterRedux.syncHistoryWithStore)(_reactRouter.browserHistory, store);

_reactDom2.default.render(_react2.default.createElement(
  _reactRedux.Provider,
  { store: store },
  _react2.default.createElement(
    _reactRouter.Router,
    { history: history },
    _react2.default.createElement(_reactRouter.Route, { path: '/', component: _app2.default })
  )
), document.getElementById('tetris'));