const cartItems = []; // Array to store cart items

document.querySelectorAll(".fa-regular.fa-square-plus").forEach((addButton) => {
  addButton.addEventListener("click", function () {
    const parentDiv = this.parentElement.parentElement.parentElement; // Select the subitems container

    const imageElement = parentDiv.querySelector(".image img");
    const productNameElement = parentDiv.querySelector(".details1 h7");
    const priceElement = productNameElement.textContent.split("Rs.")[1]; // Extract price

    const product = {
      image: imageElement.src,
      name: productNameElement.textContent.split("<br>")[0], // Extract name
      price: parseFloat(priceElement),
      quantity: 1, // Initial quantity
    };

    // Update cart items array and display cart data
    cartItems.push(product);
    updateCart(cartItems);
  });
});

function updateCart(items) {
  // Clear existing cart content (if needed) and create cart container
  const cartContainer = document.getElementById("cart-div"); // Replace with your cart container ID
  cartContainer.innerHTML = ""; // Clear content

  if (items.length === 0) {
    cartContainer.innerHTML = "Your cart is empty.";
    return;
  }

  // Display cart items
  items.forEach((item) => {
    const cartItem = document.createElement("div");
    cartItem.classList.add("cart-item");

    const image = document.createElement("img");
    image.src = item.image;
    cartItem.appendChild(image);

    const details = document.createElement("div");
    details.classList.add("cart-item-details");

    const name = document.createElement("p");
    name.textContent = item.name;
    details.appendChild(name);

    const price = document.createElement("p");
    price.textContent = `Rs. ${item.price.toFixed(2)}`; // Formatting for two decimal places
    details.appendChild(price);

    const quantity = document.createElement("p");
    quantity.textContent = `Quantity:${item.quantity}`;

    const quantityUp = document.createElement("button");
    quantityUp.textContent = "+";
    quantityUp.addEventListener("click", () => {
      item.quantity++;
      quantity.textContent = `Quantity: ${item.quantity}`;
      updateCart(cartItems); // Update cart display
    });

    const quantityDown = document.createElement("button");
    quantityDown.textContent = "-";
    quantityDown.addEventListener("click", () => {
      if (item.quantity > 1) {
        item.quantity--;
        quantity.textContent = `Quantity: ${item.quantity}`;
        updateCart(cartItems); // Update cart display
      } else {
        // Optionally handle removing the item from the cart
        // Example:
        removeFromCart(item);
      }
    });

    details.appendChild(quantity);
    details.appendChild(quantityUp);
    details.appendChild(quantityDown);

    cartItem.appendChild(details);

    cartContainer.appendChild(cartItem);
  });

  // Additional calculations or updates based on cart items (e.g., total price) can be done here
}

function removeFromCart(item) {
  // Implement logic to remove item from cart data structure and update cart display
  cartItems.splice(cartItems.indexOf(item), 1);
  updateCart(cartItems);
}

const addToCartButton = document.querySelector(".add-to-cart-button"); // Replace with your button selector

addToCartButton.addEventListener("click", async () => {
  const itemId = addToCartButton.dataset.itemId; // Extract item ID from button data
  const imageUrl = document.querySelector("#item-image").src; // Extract image URL
  const name = document.querySelector("#item-name").textContent; // Extract item name
  const price = parseFloat(
    document.querySelector("#item-price").textContent.slice(3)
  ); // Extract and parse price
  const quantity = document.querySelector("#item-quantity").value || 1; // Get chosen quantity (default 1)

  const itemData = { itemId, imageUrl, name, price, quantity };

  try {
    const response = await fetch("/api/cart", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(itemData),
    });

    if (response.ok) {
      // Item added successfully!
      // Handle response and update cart accordingly
    } else {
      console.error("Error adding item to cart:", response.statusText);
      // Handle error appropriately (e.g., display an error message to the user)
    }
  } catch (error) {
    console.error("Error sending API request:", error.message);
    // Handle API call errors
  }
});