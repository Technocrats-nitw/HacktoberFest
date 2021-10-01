const mongoose = require('mongoose');

const Dishes = require('./models/dishes');

const url = 'mongodb://127.0.0.1:27017/Trivalent';
const connect = mongoose.connect(url);

connect.then((db) =>{
    console.log('Connected to server ');

    Dishes.create({
        name: "Uthapizza",
        description: "test"
    })
    .then((dish)=>{
        console.log(dish);

        return Dishes.findByIdAndUpdate(dish._id, {
            $set: {description: 'updated test'}
        },{
                new: true
        }).exec();
    })
    .then((dish)=>{
        console.log(dish);

        dish.comments.push({
            rating: 5,
            author: 'shubhank',
            comment: 'Its just awesome !'
        });

        return dish.save();
    })
    .then((dish)=>{
        console.log(dish);

        return Dishes.remove({});
    })
    .then(()=>{
        return mongoose.connection.close();
    })
    .catch((err)=> {console.log(err)});
});