const lineReader = require('line-reader');
var path = require('path');

lineReader.eachLine('filelist.txt', function(line) {
  var filename = path.basename(line).split('.').slice(0, -1).join('.');
  var dirname = path.dirname(line);
  filename = filename.replace(")", "_");
  filename = filename.replace("(", "_");
  filename = filename.replace(" ", "_");
  pushcommand("pdftoppm " + line + " " + filename + " -png " + dirname);
  console.log( line + ' : ok');
});

/*
function namecheck(filename){
  var fs = require('fs');
  
fs.rename('/path/to/Afghanistan.png', '/path/to/AF.png', function(err) {
    if ( err ) console.log('ERROR: ' + err);
});
  
  return translated;
}

*/
function pushcommand(cmdToLaunch) {

  var exec = require('child_process').exec;

  function execCB(error, stdout, stderr) {
    if (error) {
      console.error(`exec error: ${error}`);
      return;
    }
    console.log('stdout: ' + stdout);
    console.log('stderr: ' + stderr);
  }

  var app = exec(cmdToLaunch, execCB);

}
