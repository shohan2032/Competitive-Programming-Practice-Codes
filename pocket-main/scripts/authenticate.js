// console.log(document.getElementsByClassName("text-field"))
// console.log(document.getElementById("text-field"))
// console.log(document.getElementsByTagName("input"))
document.getElementById('errorMessage').style.display= 'none'
let formElement = document.getElementById('form-container');
formElement.addEventListener('submit',function(event){
  event.preventDefault();
  // 
  let userName= document.querySelector("input[name='username']").value;
  let secret= document.querySelector("input[name='secret']").value;
  // console.log(userName, secret)
  if(userName === 'My pocket' && secret==='baperTaka'){
    // hide the error message-approach 1
    document.getElementById('errorMessage').style.display= 'none';
    // clear the entire div using innerHTML or textContent approach -2
    let errorContainer = document.getElementById('error-message');
    errorContainer.textContent=""
    // errorContainer.innerHTML=""
     window.location.replace('wallet.html')
  }else{
    let errorContainer = document.getElementById('error-message');
    errorContainer.textContent=""
    let p = document.createElement('p');
    p.innerText = "Either wrong username or secret"
    // console.log(p);
    errorContainer.appendChild(p);

    // approach 2
    // document.getElementById('errorMessage').style.display= 'block'

  }


})
