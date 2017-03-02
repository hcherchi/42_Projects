export default function loseGame(data) {
  return {
    type: 'server/loseGame',
    data,
  }
}
