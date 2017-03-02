import { createStore, applyMiddleware, combineReducers, compose } from 'redux'
import React from 'react'
import ReactDom from 'react-dom'
import { Provider } from 'react-redux'
import thunk from 'redux-thunk'
import createLogger from 'redux-logger'
import { Router, Route, browserHistory } from 'react-router'
import { syncHistoryWithStore, routerReducer } from 'react-router-redux'
import io from 'socket.io-client'
import socketIoMiddleWare from './middleware/socketIoMiddleWare'
import reducer from './reducers'
import App from './containers/app'

require("babel-core/register");
require("babel-polyfill");

const configureStore = (reducer, socket) => createStore(
  combineReducers({
    routing: routerReducer,
    game: reducer,
  }),
  composeEnhancers(
  applyMiddleware(
    socketIoMiddleWare(socket),
    thunk
  )),
)

const socket = io('localhost:5000')
const composeEnhancers = window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose
const store = configureStore(reducer, socket)
const history = syncHistoryWithStore(browserHistory, store)

ReactDom.render((
  <Provider store={store}>
    <Router history={history}>
      <Route path="/" component={App} />
    </Router>
  </Provider>
), document.getElementById('tetris'))
