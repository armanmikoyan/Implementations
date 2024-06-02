const STATE = {
   PENDING: "PENDING",
   FULFILLED: "FULFILLED",
   REJECTED: "REJECTED",
}

class MyPromise {
   #successCallbackes = [];
   #failCallbackes = [];
   #state = STATE.PENDING;
   #value;
   #onSuccesBindedThis = this.#onSuccess.bind(this)
   #onFailBindedThis = this.#onFail.bind(this)

   constructor(callBack) {  
      try {
         callBack(this.#onSuccesBindedThis, this.#onFailBindedThis);
      }
      catch(err) {
         this.#onFailBindedThis(err)
      }
   }

   #executeCallbackes() {
      if (this.#state == STATE.REJECTED)
      {
         this.#failCallbackes.forEach((cb) => {
            cb(this.#value);  
         });
      }
      
      else if (this.#state == STATE.FULFILLED)
      {
         this.#successCallbackes.forEach((cb) => {
            cb(this.#value); 
         });
      }
   }

   #onSuccess(value) {
      if (this.#state !== STATE.PENDING) return;

      this.#state = STATE.FULFILLED;
      this.#value = value;

      this.#executeCallbackes() // when async operation has ended 
   }

   #onFail(value) {
      if (this.#state !== STATE.PENDING) return;

      this.#state = STATE.REJECTED;
      this.#value = value;

      this.#executeCallbackes() // when async operation has ended 
   } 

   then(callback) {
      if (this.#state === STATE.PENDING)
      {
         this.#successCallbackes.push(callback); //   there is an async operation 
         return;
      }

      if (this.#state === STATE.FULFILLED)
      {
         callback(this.#value);  // when there is not an async operation 
      }                        
  }

  catch(callback) {
      if (this.#state === STATE.PENDING)
      {
         this.#failCallbackes.push(callback);    //   there is an async operation 
         return;
      }
      if (this.#state === STATE.REJECTED)
      {
         callback(this.#value);  // when there is not an async operation 
      }
   }
}


// TEST
let myP = new MyPromise((resolve, reject) => {
   let value = 10;
   setTimeout(() => {
      if (value > 5)
      {
         resolve(value);
      }
      else
      {
         reject(value)
      }
   }, 0)
})

myP.then((val)=>{
   console.log(1, val)
})

myP.catch((val) => {
   console.log("catch")
})

setInterval(()=>{
   console.log("waiting")
}, 3000)
