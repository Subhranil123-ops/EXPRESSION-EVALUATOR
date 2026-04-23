const express = require("express");
const router = express.Router();
const homeController = require("../controller/home.js");
router.get("/home", homeController.renderHome);
router.get("/analyze", homeController.renderAnalyzeForm);
router.post("/analyze", homeController.postAnalyzeForm);
router.get("/expression", homeController.renderExpressionForm);
router.post("/expression", homeController.postExpressionForm);
module.exports = router;