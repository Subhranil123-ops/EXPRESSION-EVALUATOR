const express = require("express");
const router = express.Router();
const homeController = require("../controller/home.js");
router.get("/home", homeController.renderHome);
router.get("/analyze", homeController.renderAnalyzePage);

module.exports = router;