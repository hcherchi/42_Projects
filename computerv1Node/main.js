const _ = require('lodash')

const fillDatas = function (piece, datas, k) {
  const subsplit = piece.split(/[∗|\*]X\^/)
  if (subsplit.length !== 2) { return true }

  const coef = !isNaN(Number(subsplit[0])) ? k * Number(subsplit[0]) : null
  const pow = /[0-9]+/.test(subsplit[1]) ? parseInt(subsplit[1]) : null
  if (coef == null || pow == null) { return true }

  samePow = _.find(datas, data => data.pow === pow)
  if (samePow) {
    samePow.coef += coef
  } else {
    datas.push({ coef, pow })
  }
}

const getParams = function (input) {
  const clean = input.replace(/ /g, '').replace(/-/g, '+-')
  const split = clean.split('=')

  if (!split || split.length !== 2) { return console.log('Bad format') }

  const splitright = split[0].split('+')
  const splitleft = split[1].split('+')

  const datas = []
  let error = false

  splitright.forEach(piece => error = fillDatas(piece, datas, 1))
  splitleft.forEach(piece => error = fillDatas(piece, datas, -1))

  if (error) { return console.log('Bad format') }

  return datas
}

const getReducedForm = function (datas) {
  const tab = datas.map((data, index) => {
    if (data.coef < 0) {
      return `(${data.coef}) * X^${data.pow}`
    } else {
      return `${data.coef} * X^${data.pow}`
    }
  })
  return `${tab.join(' + ')} = 0`
}

const resolve0 = function (datas) {
  const c = _.find(datas, data => data.pow === 0).coef
  if (c === 0) {
    console.log('Every Real numbers are solutions')
  } else {
    console.log('No solutions')
  }
}

const resolve1 = function (datas) {
  let a = _.find(datas, data => data.pow === 1)
  let b = _.find(datas, data => data.pow === 0)

  a = a ? a.coef : 0
  b = b ? b.coef : 0

  const s = strip(- b / a)
  console.log(`X = ${s}`)
}

const sqrt = function(nb) {
    const precision = 0.00001;
    let Un = nb;

    while ((Un * Un >= nb + precision) || (Un * Un <= nb - precision))
    {
        Un = ( Un + nb / Un ) / 2 ;
    }
    return Un;
}

const strip = function (number) {
    return (parseFloat(number).toPrecision(4));
}

const resolve2 = function (datas) {
  let a = _.find(datas, data => data.pow === 2)
  let b = _.find(datas, data => data.pow === 1)
  let c = _.find(datas, data => data.pow === 0)

  a = a ? a.coef : 0
  b = b ? b.coef : 0
  c = c ? c.coef : 0

  const delta = b * b - 4 * a * c

  if (delta < 0) {
    console.log('Delta < 0: No solutions')
  } else if (delta === 0) {
    console.log('Delta = 0: One solution')
    const s = strip(- b / (2 * a))
    console.log(`X = ${s}`)
  } else {
    console.log('Delta > 0: Two solutions')
    const s1 = strip((- b - sqrt(delta)) / (2 * a))
    const s2 = strip((- b + sqrt(delta)) / (2 * a))
    console.log(`X1 = ${s1}`)
    console.log(`X2 = ${s2}`)
  }
}

const main = function () {
  if (process.argv.length !== 3) { return console.log('No params') }

  const datas = getParams(process.argv[2])

  if (!datas) { return }

  const reducedForm = getReducedForm(datas)
  const degree = _.maxBy(datas, data => data.pow).pow

  console.log(datas)
  console.log(`Reduced form: ${reducedForm}`)
  console.log(`Equation of degree ${degree}`)

  if (degree == 2) {
    resolve2(datas)
  } else if (degree == 1) {
    resolve1(datas)
  } else if (degree == 0) {
    resolve0(datas)
  } else {
    console.log('I cannot solve an equation of degree > 2')
  }
}

main()
