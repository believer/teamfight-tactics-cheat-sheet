const purgecss = require("@fullhuman/postcss-purgecss")({
  content: ["./lib/js/src/**/*.js"],
  defaultExtractor: content => content.match(/[A-Za-z0-9-_:/]+/g) || []
});

module.exports = {
  plugins: [require("tailwindcss"), require("autoprefixer")]
};
