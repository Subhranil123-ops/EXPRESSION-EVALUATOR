const axios = require('axios');
module.exports.renderHome = (req, res) => {
    res.render("./pages/home.ejs");
}

module.exports.renderExpressionForm = (req, res) => {
    res.render("./pages/expression.ejs", { data: null, error: null });
}

module.exports.postExpressionForm = async (req, res) => {
    const { expression } = req.body;
    try {
        console.log("Sending request to C++...");
        const result = await axios.post('http://localhost:5000/expression', { expression });
        res.render("./pages/expression.ejs", { data: result.data, error: null });
        console.log("Response from C++:", result.data);
    } catch (err) {
        console.log("Response from C++:", err.response.data);
        console.log("STATUS:", err.response?.status);
        res.render("./pages/expression.ejs", { data: null, error: err.response.data?.message || "Something went wrong" });
    }

}

module.exports.renderAnalyzeForm = (req, res) => {
    res.render("./pages/analyze.ejs", { data: null, error: null });
}

module.exports.postAnalyzeForm = async (req, res) => {
    const { code } = req.body;
    try {
        console.log("Sending request to C++...");
        const result = await axios.post('http://localhost:5000/analyze', { code });
        res.render("./pages/analyze.ejs", { data: result.data, error: null });
        console.log("Response from C++:", result.data);
    } catch (err) {
        console.log("Response from C++:", err.response.data);
        console.log("STATUS:", err.response?.status);
        res.render("./pages/analyze.ejs", { data: null, error: err.response.data?.message || "Something went wrong" });
    }
}





