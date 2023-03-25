const fs = require('fs');

const readFile = function(fileName){
    return new Promise((resolve,rejects)=>{
        fs.readFile(fileName,(err,data)=>{
            if(err) rejects(err);
            resolve(data);
        });
    });
}

