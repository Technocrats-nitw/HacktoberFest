const chalk = require('chalk')
const fs = require('fs')

const addNote = (title,body)=>{
    const notes = loadNotes()
    // const duplicateNotes = notes.filter((note)=>note.title===title);
    const duplicateNote = notes.find((note) => note.title === title);

    debugger;

    if(!duplicateNote)
    {
        notes.push({
            title:title,
            body:body
        })
        saveNotes(notes);
        console.log(chalk.green.inverse('New note added'));
    } else {
        console.log(chalk.red.inverse('Note title taken'));
    }
}

const removeNote = (title)=>{
    const notes = loadNotes();
    const notesToKeep = notes.filter((note)=>note.title !== title);
    if(notesToKeep.length === notes.length){
        console.log(chalk.red.inverse('No note found!'));
    } else{
        saveNotes(notesToKeep);
        console.log(chalk.green.inverse('Note removed'));
    }
}

const listNotes = () => {
    console.log(chalk.inverse('Your Notes'));
    const notes = loadNotes();
    notes.forEach(note => {
        console.log(note.title);
    });
}

const readNote = (title)=>{
    const notes = loadNotes();
    const note = notes.find((note) => note.title === title);

    if(note){
        console.log(chalk.inverse(note.title));
        console.log(note.body)

    } else {
        console.log(chalk.red.inverse('No note found'));
    }
}

const saveNotes = (notes)=>{
    const dataJSON = JSON.stringify(notes);
    fs.writeFileSync('notes.json',dataJSON);
}

const loadNotes = ()=>{
    try{
        const dataBuffer = fs.readFileSync('notes.json');
        const dataJSON = dataBuffer.toString();
        return JSON.parse(dataJSON);
    } catch(e){
        return [];
    }
}

module.exports = {
    addNote : addNote,
    removeNote : removeNote,
    listNotes : listNotes,
    readNote : readNote
}