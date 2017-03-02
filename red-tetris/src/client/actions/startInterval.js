export default function startInterval(data) {
  return {
    type: 'client/startInterval',
    data,
  }
}
