const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');

const url = "mongodb://127.0.0.1:27017/";
const dbname = 'Trivalant';

const dboper = require('./operations');

MongoClient.connect(url,  {useUnifiedTopology: true, useNewUrlParser: true, useCreateIndex: true }).then((err, client) =>{

    assert.equal(err,null);
    console.log('Connected ');

    const db = client.db(dbname);
    dboper.insertDocument(db, {name: "Vadonut", description: "Test"}, 'dishes')
    .then((result)=>{
        console.log(' Insert Document:\n', result.ops);

        return dboper.findDocument(db, 'dishes')
    })
    .then((docs)=>{
            console.log('Found documents:\n', docs);

            return dboper.updateDocument(db, { name: "Vadonut" },
            { description: "Updated Test" }, "dishes")
     })
    .then((result)=>{
            console.log('Updated Document\n', result.result);

            return dboper.findDocument(db, 'dishes')
     })
     .then((docs) =>{
            console.log('Found Docs:\n', docs);

            return db.dropCollection('dishes')
     })
     .then((result)=>{
            console.log('Dropped Collection', result);

            client.close();
    })
    .catch((err)=>console.log(err))

})