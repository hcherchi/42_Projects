export default function nextTurn(data) {
  return {
    type: 'server/nextTurn',
    data,
  }
}
