const express = require('express');
const expressLayouts = require('express-ejs-layouts')
const fs = require('fs');
const formData = require('express-form-data');
// const bootstrap = require('bootstrap')

const path = require('path');
const app = express()
const port = 3000

const pathPublic = path.join(__dirname, 'public')
const pathViews = path.join(pathPublic, 'views')
const pathLayouts = path.join(pathViews, 'layouts')
const pathPartials = path.join(pathViews, 'partials')
const storageFile = '/home/www-dev/www/green-house/raspbarrypi/src/storage/sensor.json'

require('dotenv').config();

app.use(formData.parse({}));
app.use(express.json());
app.use(express.static('public'))
app.use('/css', express.static(path.join(pathPublic, 'css')))
app.use('/js', express.static(path.join(pathPublic, 'js')))
app.use('/img', express.static(path.join(pathPublic, 'img')))

app.use(expressLayouts)
app.set('layout', path.join(pathLayouts, 'default'));
app.set("views", pathViews);
app.set('view engine', 'ejs');
// bodyParser.urlencoded({ extended: true });


const readDateJSON = () => {
  let data = fs.readFileSync(storageFile, 'utf8');
  data = JSON.parse(data);
  return data[findClosestKey(data)];   
}


const findClosestKey = (data) => {
  let now = new Date();  // aktuelles Datum und Uhrzeit
  let keys = Object.keys(data);
  let closestKey = keys.reduce((prev, curr) => {
    let prevDiff = Math.abs(now - new Date(prev));
    let currDiff = Math.abs(now - new Date(curr));
    return (currDiff < prevDiff ? curr : prev);
  });
  return closestKey;
}

app.get('/', (req, res) => {
  let data = readDateJSON();
  res.render('index', {
    title: 'Green-House',
    sensorData: data
  });
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})