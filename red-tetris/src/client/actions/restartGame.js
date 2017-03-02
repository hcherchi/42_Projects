export default function restartGame(data) {
  return {
    type: 'server/restartGame',
    data,
  }
}
