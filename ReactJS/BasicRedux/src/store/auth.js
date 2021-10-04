import { createSlice } from '@reduxjs/toolkit';

const initialAuthState = {isAuthenticated:false};

// createSlice :  A function that accepts an initial state, an object of reducer functions, and a "slice name", and automatically generates action creators and action types that correspond to the reducers and state.

const authSlice = createSlice({
    name : 'auth',
    initialState: initialAuthState,
    reducers:{
        login (state){
            state.isAuthenticated = true;
        },
        logout (state){
            state.isAuthenticated = false;
        },
    }

});

export const authActions = authSlice.actions;

export default authSlice;