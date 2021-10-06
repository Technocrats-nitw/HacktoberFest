# Lazy rendering in React (using `Suspense` and `React.lazy`)

This app is a small example that shows how to use `React.lazy` (compatible with dynamic import of javascript) to achieve ***Lazy Rendering*** which can improve performance and build a better experience for users

## Lazy Rendering
- Lazy rendering is just importing the components in a lazy manner i.e. importing on demand.
- This may not may not make sense when used in a small react app as the one used in this example, but when the app grows, making unnecessary imports may slow down the app.
- This is definitely a performance overhead since we are delaying the rendering just because we need some imports to be done.
- It leads to a **bad User Experience** of the app.
- So, importing huge components only on demand will speed up the initial render and thus leads to better User Experience.
- Lazy Rendering is one of the best practices used in building React apps.

<hr>

## What is `React.lazy()`
- It is a new function in react that lets you load react components lazily through code splitting without help from any additional libraries. 
- Lazy loading is the technique of rendering only-needed or critical user interface items first, then quietly unrolling the non-critical items later.

## `Suspense` component
- `<Suspense />` is a special react component, required by the `lazy` function, used to wrap the lazy components.
- It takes a prop called `fallback` which is also a React component that you want to render while we are importing the lazy components.


## How does it work
- If you run this react app, when you visit the 'about' or 'contact us' page for the first time, you can observe that a text saying "Loading..." for a brief amount of time and then page being rendered.
- This is because the `fallback` that we have passed to the <Suspense /> is being rendered while the app is importing the lazy page into App.ts.