import csv from 'csvtojson'
import _ from 'lodash'
import fs from 'fs'

const datas = []
const learningRate = 0.1
const iterations = 6000


const estimatePrice = (theta0, theta1, elem0) => theta0 + theta1 * elem0

const getCost = (theta0, theta1, datas) => (1 / (2 * datas.length)) * datas.reduce((sum, elem) => sum + Math.pow(estimatePrice(theta0, theta1, elem[0]) - elem[1], 2), 0)

const getParams = (rowDatas) => {
  let tmp0
  let tmp1
  let theta0 = 0
  let theta1 = 0

  const min = rowDatas.reduce((min, elem) => elem[0] < min ? elem[0] : min, rowDatas[0][0])
  const max = rowDatas.reduce((max, elem) => elem[0] > max ? elem[0] : max, rowDatas[0][0])
  const datas = rowDatas.map(elem => [(elem[0] - min) / (max - min), elem[1]])

  for (let i = 0; i < iterations; i++) {
    tmp0 = (learningRate / datas.length) * datas.reduce((sum, elem) => sum + (estimatePrice(theta0, theta1, elem[0]) - elem[1]), 0)
    tmp1 = (learningRate / datas.length) * datas.reduce((sum, elem) => sum + (estimatePrice(theta0, theta1, elem[0]) - elem[1]) * elem[0], 0)

    theta0 -= tmp0
    theta1 -= tmp1
  }

  const toWrite = `export default {teta0: ${theta0},teta1: ${theta1},min: ${min}, max: ${max}}`
  fs.writeFile('./params.js', toWrite, (err) => err ? console.log('Error While writing file') : console.log('Params successfully found'))
}

csv({noheader:true})
.fromFile('data.csv')
.on('json', (elem, index) => {
  const toPush = []
  toPush[0] = parseInt(elem.field1)
  toPush[1] = parseInt(elem.field2)
  if (index != 0) datas.push(toPush)
})
.on('done', error => {
  getParams(datas)
})
