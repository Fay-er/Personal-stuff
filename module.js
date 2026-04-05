export default class Person{
    constructor (name) {
        this.name = name;
    };

    sayHello () {
        return `Hi, I'm ${this.name}.`;
    }
}

export const greet = (name) => {return (`Hi ${name}!`)};