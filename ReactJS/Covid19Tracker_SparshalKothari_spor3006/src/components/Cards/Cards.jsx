import React from "react"
import {Card, CardContent, Typography , Grid } from '@material-ui/core'
import CountUp from 'react-countup'
import styles from './Cards.module.css' 
import cx from 'classnames';
const Cards = ({data:{confirmed , recovered , deaths , lastUpdate}}) => {
    if(!confirmed){
        return 'Loading...'
    }
    return (
    <div className = {styles.container}>
        <Grid container spacing = {3} justify ="center">
            <Grid item component={Card} xs={12} md={3} className={cx(styles.card , styles.infected)}>
                <CardContent>
                    <Typography color = "textSecondaray" gutterBottom>Infected</Typography>
                    <Typography variant="h5">
                        <CountUp start={0} end ={confirmed.value} duration={1.5} seperator =','/>
                    </Typography>
                    <Typography color = "textSecondary">{new Date(lastUpdate).toDateString()}</Typography>
                    <Typography variant="body2">Number of active cases of COVID-19 </Typography>
                </CardContent>
            </Grid>
            <Grid item component={Card} xs={12} md={3} className={cx(styles.card , styles.recovered)}>
                <CardContent>
                    <Typography color = "textSecondaray" gutterBottom>Recovered</Typography>
                    <Typography variant="h5">
                        <CountUp start={0} end ={recovered.value} duration={1.5} seperator =','/>
                    </Typography>
                    <Typography color = "textSecondary">{new Date(lastUpdate).toDateString()}</Typography>
                    <Typography variant="body2">Number of recoveries from COVID-19 </Typography>
                </CardContent>
            </Grid>
            <Grid item component={Card} xs={12} md={3} className={cx(styles.card , styles.deaths)}>
                <CardContent>
                    <Typography color = "textSecondaray" gutterBottom>Deaths</Typography>
                    <Typography variant="h5">
                        <CountUp start={0} end ={deaths.value} duration={1.5} seperator =','/>
                    </Typography>                    
                    <Typography color = "textSecondary">{new Date(lastUpdate).toDateString()}</Typography>
                    <Typography variant="body2">Number of deaths from COVID-19 </Typography>
                </CardContent>
            </Grid>
        </Grid>

    </div>
    )
}

export default Cards