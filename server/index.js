const express = require("express");
const path = require("path");
const engine = require("ejs-mate");

const app = express();
const port = 3000;
const homePage = require("./routes/home.js");
app.engine("ejs", engine);
app.set("view engine", "ejs")
app.set("views", path.join(__dirname, "views"));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use("/", homePage);
app.listen(port, () => console.log("The app is listening on the port : ", port));