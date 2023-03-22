const chalk=require('chalk')

//import chalk from 'chalk@4.1.2';

console.log(chalk.blue('Hello World!'));
console.log(chalk.blue.bgRed.bold("Hello World"));

console.log(chalk.blue("I am blue line" + chalk.red.underline.bold(" with red substring ")+"that becomes blue again."))