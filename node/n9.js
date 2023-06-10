var events = require('events');
var em = new events.EventEmitter();

var listen1 = function listener1()
{
    console.log('First listener is called');
}

var listen2 = function listener2()
{
    console.log('Second listener is called');
}

em.on('connection1',listen1);
em.addListener('connection1',listen2);
em.emit("connection1")