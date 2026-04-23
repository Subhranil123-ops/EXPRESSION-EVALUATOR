const axios = require('axios');
module.exports.renderHome = (req, res) => {
    res.render("./pages/home.ejs");
}

module.exports.renderExpressionForm = (req, res) => {
    res.render("./pages/expression.ejs", { data: null, error: null, expression: "" });
}

module.exports.postExpressionForm = async (req, res) => {
    const { expression } = req.body;
    try {
        const result = await axios.post('http://localhost:5000/expression', { expression });
        res.render("./pages/expression.ejs", { data: result.data, error: null, expression: expression });
    } catch (err) {
        res.render("./pages/expression.ejs", { data: null, error: err.response.data?.message || "Something went wrong", expression: expression });
    }

}

module.exports.renderAnalyzeForm = (req, res) => {
    res.render("./pages/analyze.ejs", { data: null, error: null, code: "" });
}

module.exports.postAnalyzeForm = async (req, res) => {
    const { code } = req.body;
    try {
        const result = await axios.post('http://localhost:5000/analyze', { code });
        res.render("./pages/analyze.ejs", { data: result.data, error: null, code: code });
    } catch (err) {
        res.render("./pages/analyze.ejs", { data: null, error: err.response.data?.message || "Something went wrong", code: code });
    }
}





