import React from 'react';
import styles from './Bar.module.scss';

const Bar = ({ height, loading }) => {
  let extraClasses = styles.item;
  extraClasses += loading ? ` ${styles.loading}` : '';
  let alpha = (height / 563) + 0.15;
  let customStyles = loading ? {height: `${height}px`} : {height: `${height}px` , backgroundColor: `rgb(24, 24, 91, ${alpha})`};
  return <div style={customStyles} className={extraClasses} ></div>;
};

export default Bar;
