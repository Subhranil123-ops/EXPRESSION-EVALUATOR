const axios = require('axios');
module.exports.renderHome = (req, res) => {
    res.render("./pages/home.ejs");
}

module.exports.renderExpressionForm = (req, res) => {
    res.render("./pages/expression.ejs");
}

module.exports.postExpressionForm = async (req, res) => {
    const { code } = require(req.body);

}

module.exports.renderAnalyzeForm = (req, res) => {
    res.render("./pages/analyze.ejs");
}

module.exports.postAnalyzeForm = async (req, res) => {
    const { code } = req.body;
    try {
        const result = await axios.post('http://localhost:5000/analyze', { code });
        res.send(result.data);
    } catch (err) {
        console.error(err);
        res.status(500).send("Error analyzing code");
    }
}





