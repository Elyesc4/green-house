require('dotenv').config();
const express = require('express');
const app = express();
const bcrypt = require('bcrypt');
const bodyParser = require('body-parser');
const crypto = require('crypto');
const port = process.env.PORT || 3000;
const corsOptions = {
    "origin": "*",
    optionsSuccessStatus: 200
}

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.get('/a', (req, res) => {
  res.send('Hello World!')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})