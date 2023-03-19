const {
  application
} = require('express');
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

require('dotenv').config();

app.use(formData.parse({}));
app.use(express.static('public'))
app.use('/css', express.static(path.join(pathPublic, 'css')))
app.use('/js', express.static(path.join(pathPublic, 'js')))
app.use('/img', express.static(path.join(pathPublic, 'img')))

app.use(expressLayouts)
app.set('layout', path.join(pathLayouts, 'default'));
app.set("views", pathViews);
app.set('view engine', 'ejs');
// bodyParser.urlencoded({ extended: true });

app.get('/', (req, res) => {
  res.render('index', {
    title: 'Home 🏡'
  });
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})