import React from 'react';

import Bar from '../Bar/Bar';
import styles from './Container.module.scss';

const Container = ({ array }) => {
  return (
    <div className={styles.container}>
      {array.map((val, idx) => (
        <Bar key={idx} height={val.value} loading={val.loading} />
      ))}
    </div>
  );
};

export default Container;
