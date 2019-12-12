// Lists files in a given directory. And saves as a .txt file line by line
// Todo: Make structure object oriented.

const testFolder = __dirname;

var walk    = require('walk');
var path = require('path');

const fs = require('fs');
var logger = fs.createWriteStream('filelist.txt', {
  flags: 'w',
  encoding: 'utf8'
})

var walker  = walk.walk(testFolder, { followLinks: false });

walker.on('file', function(root, stat, next) {
    var line = root + '/' + stat.name;
    console.log(line);
    
    if(IsPDF(line)){
        logger.write(line+ "\n");
      }else{
        console.log('false');
      }

    next();
});

walker.on('end', function() {

    logger.end()
});


function IsPDF(a) {
    a = path.extname(a);
    if (a == ".pdf" || a == ".PDF")
    return true;
    else{
        return false;
    }
        
  }
