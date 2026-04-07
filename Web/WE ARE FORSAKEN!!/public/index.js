let items = document.getElementsByClassName("item");

function clicked(val){
    let childrenElements = val.children;

        for(let i = 0; i < childrenElements.length; i++){
            if((childrenElements[i].tagName != "P")){
                childrenElements[i].style.margin = "0";
            }

            if(childrenElements[i].tagName == "P"){
                childrenElements[i].style.position = "absolute";
                childrenElements[i].style.transform = "translate(55%, 15%)";
                childrenElements[i].style.width = "200%";
                childrenElements[i].style.opacity = "100%";

                console.log((childrenElements[i].tagName == "P"));
            }
        }

        val.style.position= "absolute";
        val.style.transform = "translate(15%, 3%)";
        val.style.width = "25%";

        for(let i = 0; i < items.length; i++){
            if(items[i] != val){
                items[i].style.opacity = "0";
            }
        }
};