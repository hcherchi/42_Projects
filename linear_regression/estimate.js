import readline from 'readline'
import params from './params'

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.question('What is the mileage of your car? ', (answer) => {

  const {
    teta0,
    teta1,
    max,
    min
  } = params

  const normalData = (parseInt(answer) - min) / (max - min)
  const estimation = teta0 + teta1 * normalData
  console.log(`Estimated price: ${estimation}$`)
  rl.close()
})
