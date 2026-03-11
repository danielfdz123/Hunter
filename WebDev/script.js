//Stuff for the buttons and their actions
let addList = document.getElementById("add");
let RemoveList= document.getElementById("delete");

//ADD BUTTON FUNCTION
addList.onclick = function() 
{
    //Accesses the ordered list
    let ol = document.querySelector('ol');

    //Creates a new TEXT element
    let li = document.createElement('li');
    li.innerText = 'Everyone else :)';

    //Adds the text element to the list
    ol.append(li)
};

//REMOVE BUTTON FUNCTION
RemoveList.onclick = function() 
{
    //Calls ordered list via ID
    let myList = document.getElementById("OrderedList");

    //Last item in the list is set as a child
    let lastItem = myList.lastChild;

    //Removes last item from the list
    myList.removeChild(lastItem);
}; 