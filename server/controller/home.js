module.exports.renderHome = (req, res) => {
    res.render("./pages/home.ejs");
}

module.exports.renderExpressionPage = (req, res) => {
    res.render("./pages/expression.ejs");
}

module.exports.renderAnalyzePage = (req, res) => {
    res.render("./pages/analyze.ejs");
}