export default function getGames(data) {
  return {
    type: 'server/getGames',
    data,
  }
}
