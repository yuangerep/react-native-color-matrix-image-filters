module.exports = (api) => {
  console.warn('API', api.env('test'))
  return api.env('test')
    ? {
        presets: ['@babel/preset-env', '@babel/preset-typescript', '@babel/preset-react'],
        targets: { node: 16 }
      }
    : {
        presets: ['module:metro-react-native-babel-preset']
      }
}
