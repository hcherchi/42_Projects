import csv from 'csvtojson'

const datas = []
const learningRate = 0.00000000000001

const estimatePrice = (theta0, theta1, mileage) => theta0 + theta1 * mileage

const getCost = (theta0, theta1, datas) => (1 / (2 * datas.length)) * datas.reduce((sum, car) => Math.pow(estimatePrice(theta0, theta1, car.km) - car.price, 2), 0)

const getParams = (datas) => {
  let tmp0
  let tmp1
  let theta0 = 0
  let theta1 = 0

  for (let i = 0; i < 10000; i++) {
    console.log(getCost(theta0, theta1, datas))
    console.log(theta0, theta1)

    tmp0 = (learningRate / datas.length) * datas.reduce((sum, car) => sum + (estimatePrice(theta0, theta1, car.km) - car.price), 0)
    tmp1 = (learningRate / datas.length) * datas.reduce((sum, car) => sum + (estimatePrice(theta0, theta1, car.km) - car.price) * car.km, 0)

    theta0 -= tmp0
    theta1 -= tmp1
  }
}

csv()
.fromFile('data.csv')
.on('json', car => datas.push(car))
.on('done', error => {
  console.log(datas)
  getParams(datas)
})
